#pragma once
#include "LLVM.hpp"

#include "GenericValue.hpp"
#include "GenericType.hpp"
#include "Enviroment.hpp"
#include "ASTNode.hpp"

class ASTSymbol : public ASTNode {
public:
	std::string val;

public:
	ASTSymbol(std::string val) : val(val) {}

	virtual DataType type() const { return DataType::Symbol; }

	virtual GTPtr return_type(Enviroment &env) const {
		return env.value_map[val].type;
	}

	GenericValue to_value(Enviroment &env, llvm::IRBuilder<> &builder) {
		auto found_value = env.value_map[val];
		return found_value;
	}

	virtual std::string as_string() const { return val + " "; }
};