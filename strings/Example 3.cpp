#include <iostream>
#include <cstdint>
#include <cstring>
 
int main()
{
    	// simple usage
    	char source[] = "once upon a midnight dreary...", dest[4];
    	std::memcpy(dest, source, sizeof dest);
    	std::cout << "dest[4] = { ";
    	for (char c : dest)
        	std::cout << "'" << c << "', ";
    	std::cout << "};\n";
 
    	// reinterpreting
    	double d = 0.1;
	//std::int64_t n = *reinterpret_cast<std::int64_t*>(&d); // aliasing violation
   	std::int64_t n;
    	std::memcpy(&n, &d, sizeof(d)); // OK
 
    	std::cout << std::hexfloat << d << " is " << std::hex << n
              << " as an std::int64_t\n" << std::dec;
 
    	// object creation in destination buffer
    	struct S {
        	int x{42};
        	void print() const { std::cout << "{" << x << "}\n"; }
    	}s;
    	alignas(S) char buf[sizeof(S)];
    	S* ps = new (buf) S; // placement new
    	std::memcpy(ps, &s, sizeof s);
    	ps->print();
}
