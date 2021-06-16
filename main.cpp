// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/beached/utfcpp_iostream
//

#include <utf8/unchecked.h>

#include <cstdint>
#include <fstream>
#include <iostream>

int main( int argc, char **argv ) {
	auto in_file = std::ifstream( argv[1] );
	if( not in_file ) {
		std::cerr << "Cout not open file\n";
		exit( 1 );
	}
	auto first_stream = std::istreambuf_iterator<char>( in_file );
	auto last_stream = std::istreambuf_iterator<char>( );
	auto first = utf8::unchecked::iterator( first_stream );
	auto last = utf8::unchecked::iterator( last_stream );
	while( first != last ) {
		std::cout << static_cast<std::uint32_t>( *first ) << '\n';
	}
}
