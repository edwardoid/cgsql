#ifndef KEYWORDS_H
#define KEYWORDS_H
#include "CGSQL.h"

BEGIN_CGSQL_NS

const char* WHITES 		 = "WHITES";
const char* BLACKS 		 = "BLACKS";
const char* WINS   		 = "WINS";
const char* LOSES  		 = "LOSES";
const char* HAS    		 = "HAS";
const char* HASNT  		 = "HASNT";
const char* CONCEPT_DELIMETER    = ".";
const char* HEADER_BEGIN	 = "[";
const char* HEADER_END	         = "]";
const char* BODY_BEGIN           = "(";
const char* BODY_END	         = ")";
const char* AND_K		 = "AND";
const char* OR_K		 = "OR";
const char* XOR_K		 = "XOR";

END_CGSQL_NS

#endif // KEYWORDS_H
