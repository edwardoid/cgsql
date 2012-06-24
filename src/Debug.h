#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#define QQ(STR) #STR

#ifdef DEBUG_ASSERTIONS
#define ASSERT(EXP) {\
    if(!(EXP)) {\
         std::cout << "************************************\n" \
               << "Asserion failed: " \
               << QQ(EXP)\
               << " On line " << __LINE__ \
               << " In file " << __FILE__ << std::endl \
               << "************************************" \
               << std::endl;\
    }}
#else
#define ASSERT(EXP) (EXP)
#endif

#ifdef ENABLE_WARNINS
#define WARNING(MSG) {\
    std::cout << "Warning: " \
          << MSG << std::endl; \
    }
#else
#define WARNING(MSG){}
#endif

#define ERROR(MSG) {\
        std::cerr << MSG << std::endl;\
    }

#define SYNTAX_ERROR(STR, MSG) {\
        std::cerr << "Syntax error: " << MSG\
                  << " in: " << std::endl \
                  << STR << std::endl; \
    }

#endif // DEBUG_H
