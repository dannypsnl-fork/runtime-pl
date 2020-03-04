package researchllvm

import (
	"fmt"
	"testing"

	"github.com/llir/llvm/ir"
	"github.com/llir/llvm/ir/constant"
	"github.com/llir/llvm/ir/types"
)

func TestPuts(t *testing.T) {
	mod := ir.NewModule()

	helloWorldString := mod.NewGlobalDef("tmp", constant.NewCharArrayFromString("Hello, World!\n"))

	f := mod.NewFunc(
		"puts",
		types.I32,
		ir.NewParam("format", types.NewPointer(types.I8)),
	)
	f.Sig.Variadic = true

	main := mod.NewFunc(
		"main",
		types.I32,
	)
	mainB := main.NewBlock("")
	pointerToString := mainB.NewGetElementPtr(
		types.NewArray(14, types.I8), helloWorldString,
		constant.NewInt(types.I32, 0),
		constant.NewInt(types.I32, 0),
	)
	mainB.NewCall(f, pointerToString)
	mainB.NewRet(constant.NewInt(types.I32, 0))

	fmt.Printf("generated LLVM IR:\n\n%s\n", mod)

	executeIR(mod)
}
