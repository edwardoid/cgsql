#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#ifdef DEBUG_ASSERIONS
#define ASSERT(EXP) {\
	if(!(EXP) {\
		 std::cout << "************************************\n" \
			   << "Asserion failed: " << \
			   << QQ(EXP) << \
			   << "On line " << __LINE \
			   << " In file " << __FILE__ \
			   << "************************************\n" \
			   << std::endl;\
	}
#else
#define ASSERT(EXP) (EXP)
#endif

#endif // DEBUG_H
