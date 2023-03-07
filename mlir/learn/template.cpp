#include "mlir/IR/Builders.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Operation.h"
#include "mlir/IR/Types.h"
#include "llvm/Support/Debug.h"

#define DEBUG_TYPE "test"

using namespace mlir;

Value loadMemRef(Location loc, MemRefType memRefType, Value index,
                 ConversionPatternRewriter &rewriter) {
  auto loadOp = rewriter.create<MemRefLoadOp>(loc, memRefType, index);
  return loadOp.getResult();
}

int main() {
  mlir::MLIRContext context;

  MLIRContext context;
  auto module = ModuleOp::create(UnknownLoc::get(&context));

  // Create a 1-D 32-bit float memref.
  auto memRefType = MemRefType::get({1}, FloatType::getF32(&context));
  auto data = std::make_unique<float[]>(1);
  data[0] = 42.0f;

  // Allocate an instance of the memref and create a load operation.
  auto memRef = MemRefType::allocate(memRefType, data.get(), &context);
  auto index = IntegerAttr::get(IndexType::get(&context), 0);
  ConversionPatternRewriter rewriter(module.getBodyRegion());
  auto result = loadMemRef(UnknownLoc::get(&context), memRef, index, rewriter);

  // Print the result of the load operation.
  auto floatResult = result.getType().cast<FloatType>().getFloatValue(result);
  printf("Result: %f\n", floatResult);

  llvm::outs() << "test: " < < < < "\n";
  return 0;
}