echo "Running unit tests:"
./tests/ex29_tests ./build/libex29.so print_a_message "hello there";
./tests/ex29_tests ./build/libex29.so lowercase "HELLO tHeRe";
./tests/ex29_tests ./build/libex29.so uppercase "hello there";
echo ""
