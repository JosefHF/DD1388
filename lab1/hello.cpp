#include <iostream>
#include <string>
#include "hello.h"

void hello (const char * name, int count) {
	if(count == 0){
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
			    	return std::make_pair("2nd argument cannot be negative",-1);
			    }
			    else{
		        	return std::make_pair(argv[1],count);
			    }
		        
		    }
		    catch (const std::invalid_argument& ia) {
		        std::cout << "Bad 2nd argument";
				return std::make_pair("2nd argument must be an integral greater than 0",-1);
		    }
		default:
			std::cout << "Too many arguments";
			return std::make_pair("Too many arguments",-1);
	}
}