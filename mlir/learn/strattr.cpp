#include "mlir/IR/Builders.h"
#include "mlir/IR/MLIRContext.h"
// #include "llvm/IR/Module.h"
#include <optional>
#include  <experimental/optional>

using namespace std;

int main() {
  mlir::MLIRContext context;
  // mlir::OwningModuleRef module = mlir::ModuleOp::create(mlir::UnknownLoc::get(&context));

  mlir::OpBuilder builder(&context);

  // Create an operation with a string attribute.
  auto operation = builder.create<mlir::Operation>(
      mlir::UnknownLoc::get(&context), "my_operation",
      /*results=*/{},
      /*attributes=*/{builder.getStringAttr("my_attribute_value")});

  // Access the string attribute.
  auto attribute = operation.getAttrOfType<mlir::StringAttr>("my_attribute");
  assert(attribute && attribute.getValue() == "my_attribute_value");

  return 0;
}
