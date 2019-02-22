objects = main.o
tensorArithmetic: $(objects)
	gcc -o tensorArithmetic $(objects)

main.o : rank2Tensor.h rank3Tensor.h

clean:
	rm -f tensorArithmetic $(objects) *.gch	