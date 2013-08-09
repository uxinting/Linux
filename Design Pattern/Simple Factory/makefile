operation: operation.o
	g++ -o operation operation.o

operation.o: operation.cpp Operation.h OperationAdd.h OperationSub.h OperationMul.h OperationDiv.h
	g++ -c operation.cpp

clean:
	rm operation.o operation
