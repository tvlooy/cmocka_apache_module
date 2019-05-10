/* Hello implementation */
#include "mod_hello.h"
#include "hello.h"

void say_hello(request_rec *request) {
    ap_rprintf(request, "Hello world!");
}
