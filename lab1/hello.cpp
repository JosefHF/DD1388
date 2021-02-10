#include <iostream>
#include <string>
//#include "hello.h"

void hello (const char * name, int count) {
	if(count <= 0){
		return;
	}

	std::cout << "Hello, ";
	for(int i=0; i<count; i++){
		if(i == count-1){
			std::cout << name << "!\n";
		}
		else{
			std::cout << name << " ";
		}
  	}
}

std::pair<const char *, int> parse_args (int argc, char * argv[]) {
	switch(argc){
		case 1:
			return std::make_pair("world",1);
		case 2:
			return std::make_pair(argv[1],1);
		case 3:
			try {
		        int count = std::stoi(argv[2]);
		        if(count < 0){
		        	std::cerr << "Negative input is not accepted\n";
			    	return std::make_pair("",-1);
			    }
			    else{
		        	return std::make_pair(argv[1],count);
			    }
		        
		    }
		    catch (const std::invalid_argument& ia) {
		        std::cerr << "2nd argument has to be a number, and greater than 0\n";
				return std::make_pair("",-1);
		    }
		default:
			std::cerr << "Too many arguments\n";
			return std::make_pair("",-1);
	}
}