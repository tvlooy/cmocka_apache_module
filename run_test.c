#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "http_protocol.h"

static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void null_test_wip() {
    assert_int_equal(10, 10);
    assert_int_equal(10, 20);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(null_test_wip),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}