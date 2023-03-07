#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Types.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "llvm/Support/Debug.h"

#define DEBUG_TYPE "test"

int main() {
  mlir::MLIRContext context;

  // Create a 1-dimensional tensor with shape [3].
  mlir::OpBuilder builder(&context);
  llvm::ArrayRef<int64_t> vec = {3};
  mlir::ShapedTypeComponents components(vec);
  mlir::ShapeAdaptor adaptor(components);
  adaptor.dump();
  //   auto rankedTensorType =
  // mlir::RankedTensorType::get(shapedTypeComponentsRef, builder.getF64Type());
  LLVM_DEBUG(llvm::outs() << "test"
                          << "\n");
  for (auto dim : components.getDims()) {
    llvm::outs() << dim;
    // if (i < components.size() - 1) {
    llvm::outs() << ", ";
    // }
  }
  // printShapedTypeComponents(components);
  //   llvm::outs() << rankedTensorType << "\n";
  llvm::outs() << "test"
               << "\n";
  return 0;
}