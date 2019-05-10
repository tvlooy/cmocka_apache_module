#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "mod_hello.h"
#include "hello.h"

#include "http_protocol.h"

https://www.samba.org/~asn/sambaxp_2018_andreas_schneider_cmocka.pdf
void wrap__ap_rprintf() { }

static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void null_test_hello() {
    request_rec *request;

//    will_return(ap_rprintf, "Ok");

    say_hello(request);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(null_test_hello),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}