#include "fmt/core.h"
#include "tokenizer/tokenizer.h"
#include "analyser/analyser.h"

namespace fmt {
	template<>
	struct formatter<cc0::ErrorCode> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const cc0::ErrorCode &p, FormatContext &ctx) {
			std::string name;
			switch (p) {
			case cc0::ErrNoError:
				name = "No error.";
				break;
			case cc0::ErrStreamError:
				name = "Stream error.";
				break;
			case cc0::ErrEOF:
				name = "EOF";
				break;
			case cc0::ErrInvalidInput:
				name = "The input is invalid.";
				break;
			case cc0::ErrInvalidIdentifier:
				name = "Identifier is invalid";
				break;
			case cc0::ErrIntegerOverflow:
				name = "The integer is too big(int64_t).";
				break;
			case cc0::ErrNoBegin:
				name = "The program should start with 'begin'.";
				break;
			case cc0::ErrNoEnd:
				name = "The program should end with 'end'.";
				break;
			case cc0::ErrNeedIdentifier:
				name = "Need an identifier here.";
				break;
			case cc0::ErrConstantNeedValue:
				name = "The constant need a value to initialize.";
				break;
			case cc0::ErrNoSemicolon:
				name = "Zai? Wei shen me bu xie fen hao.";
				break;
			case cc0::ErrInvalidVariableDeclaration:
				name = "The declaration is invalid.";
				break;
			case cc0::ErrIncompleteExpression:
				name = "The expression is incomplete.";
				break;
			case cc0::ErrNotDeclared:
				name = "The variable or constant must be declared before being used.";
				break;
			case cc0::ErrAssignToConstant:
				name = "Trying to assign value to a constant.";
				break;
			case cc0::ErrDuplicateDeclaration:
				name = "The variable or constant has been declared.";
				break;
			case cc0::ErrNotInitialized:
				name = "The variable has not been initialized.";
				break;
			case cc0::ErrInvalidAssignment:
				name = "The assignment statement is invalid.";
				break;
			case cc0::ErrInvalidPrint:
				name = "The output statement is invalid.";
				break;

			case cc0::ErrLeadingZero:
				name = "Decimal integer literals other than 0 cannot have any leading 0.";
				break;
			case cc0::Err1:
				name = "Functions cannot be redefined inside functions.";
				break;
			case cc0::Err2:
				name = "Missing int type";
				break;
			case cc0::Err3:
				name = "Expression is missing content";
				break;
			case cc0::Err4:
				name = "Function name not defined";
				break;
			case cc0::Err5:
				name = "Void function cannot participate in operation";
				break;
			case cc0::Err6:
				name = "Inside the function has the same variable name as the called function name, and the function cannot be called.";
				break;
			case cc0::Err7:
				name = "Missing LEFT BRACKET";
				break;
			case cc0::Err8:
				name = "Missing Right BRACKET";
				break;
			case cc0::Err9:
				name = "Wrong number of parameters passed in";
				break;
			case cc0::Err10:
				name = "main function missing";
				break;
			case cc0::Err11:
				name = "The function has already been declared";
				break;
			case cc0::Err12:
				name = "Missing Left brace";
				break;
			case cc0::Err13:
				name = "Missing function name";
				break;
			case cc0::Err14:
				name = "Missing int or void type";
				break;
			case cc0::Err15:
				name = "Missing int type";
				break;
			case cc0::Err16:
				name = "Missing Right brace";
				break;
			case cc0::Err17:
				name = "Function has not been declared";
				break;
			case cc0::Err18:
				name = "Incomplete statement";
				break;
			case cc0::Err19:
				name = "You cannot use a return statement with no value in a non-void function.";
				break;
			case cc0::Err20:
				name = "You cannot use a return statement with a value in a function with a return type void";
				break;
			
			}	
			

			return format_to(ctx.out(), name);
		}
	};

	template<>
	struct formatter<cc0::CompilationError> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const cc0::CompilationError &p, FormatContext &ctx) {
			return format_to(ctx.out(), "Line: {} Column: {} Error: {}", p.GetPos().first, p.GetPos().second, p.GetCode());
		}
	};
}

namespace fmt {
	template<>
	struct formatter<cc0::Token> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const cc0::Token &p, FormatContext &ctx) {
			return format_to(ctx.out(),
				"Line: {} Column: {} Type: {} Value: {}",
				p.GetStartPos().first, p.GetStartPos().second, p.GetType(), p.GetValueString());
		}
	};

	template<>
	struct formatter<cc0::TokenType> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const cc0::TokenType &p, FormatContext &ctx) {
			std::string name;
			switch (p) {
			case cc0::NULL_TOKEN:
				name = "NullToken";
				break;
			case cc0::DECIMAL_LITERAL:
				name = "DecimalLiteral";
				break;
			case cc0::HEXADECIMAL_LITERAL:
				name = "HexadecimalLiteral";
				break;
			case cc0::VOID:
				name = "Void";
				break;
			case cc0::INT:
				name = "Int";
				break;
			case cc0::IDENTIFIER:
				name = "Identifier";
				break;
			case cc0::CONST:
				name = "Const";
				break;
			case cc0::IF:
				name = "If";
				break;
			case cc0::ELSE :
				name = "Else";
				break;
			case cc0::WHILE:
				name = "While";
				break;
			case cc0::PRINT:
				name = "Print";
				break;
			case cc0::SCAN:
				name = "Scan";
				break;
			case cc0::RETURN:
				name = "Return";
				break;
			case cc0::RESERVED_WORD:
				name = "ReservedWord";
				break;
			case cc0::PLUS_SIGN:
				name = "PlusSign";
				break;
			case cc0::MINUS_SIGN:
				name = "MinusSign";
				break;
			case cc0::MULTIPLICATION_SIGN:
				name = "MultiplicationSign";
				break;
			case cc0::DIVISION_SIGN:
				name = "DivisionSign";
				break;
			case cc0::EQUAL_SIGN:
				name = "EqualSign";
				break;
			case cc0::JUDGE_EQUAL_SIGN:
				name = "JudgeEqualSign";
				break;
			case cc0::LESS_SIGN:
				name = "LessSign";
				break;
			case cc0::LESS_EQUAL_SIGN:
				name = "LessEqualLSign";
				break;
			case cc0::MORE_SIGN:
				name = "MoreSign";
				break;
			case cc0::MORE_EQUAL_SIGN:
				name = "MoreEqualSign";
				break;
			case cc0::NO_EQUAL_SIGN:
				name = "NoEqualSign";
				break;
			case cc0::SEMICOLON:
				name = "Semicolon";
				break;
			case cc0::COMMA:
				name = "Comma";
				break;
			case cc0::LEFT_BRACE:
				name = "LeftBrace";
				break;
			case cc0::RIGHT_BRACE:
				name = "RightBrace";
				break;
			case cc0::LEFT_BRACKET:
				name = "LeftBracket";
				break;
			case cc0::RIGHT_BRACKET:
				name = "RightBracket";
				break;
			}
			return format_to(ctx.out(), name);
		}
	};
}

namespace fmt {
	template<>
	struct formatter<cc0::Operation> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const cc0::Operation &p, FormatContext &ctx) {
			std::string name;
			switch (p) {
			case cc0::ILL:
				name = "ILL";
				break;
			case cc0::ADD:
				name = "ADD";
				break;
			case cc0::SUB:
				name = "SUB";
				break;
			case cc0::MUL:
				name = "MUL";
				break;
			case cc0::DIV:
				name = "DIV";
				break;
			case cc0::WRT:
				name = "WRT";
				break;
			case cc0::LIT:
				name = "LIT";
				break;
			case cc0::LOD:
				name = "LOD";
				break;
			case cc0::STO:
				name = "STO";
				break;
			}
			return format_to(ctx.out(), name);
		}
	};
	template<>
	struct formatter<cc0::Instruction> {
		template <typename ParseContext>
		constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

		template <typename FormatContext>
		auto format(const cc0::Instruction &p, FormatContext &ctx) {
			std::string name;
			switch (p.GetOperation())
			{
			case cc0::ILL:
			case cc0::ADD:
			case cc0::SUB:
			case cc0::MUL:
			case cc0::DIV:
			case cc0::WRT:
				return format_to(ctx.out(), "{}", p.GetOperation());
			case cc0::LIT:
			case cc0::LOD:
			case cc0::STO:
				return format_to(ctx.out(), "{} {}", p.GetOperation(), p.GetX());
			}
			return format_to(ctx.out(), "ILL");
		}
	};
}