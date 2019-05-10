.PHONY: all
.RECIPEPREFIX = |

all: test install

build: clean
| apxs -c mod_hello.c

install: clean
| sudo apxs -i -a -c mod_hello.c
| sudo systemctl restart apache2

clean:
| rm -rf *.la *.lo *.slo .libs run_tests

test: clean
| gcc -o run_test mod_hello.c run_test.c \
|    -Wl,--unresolved-symbols=ignore-in-object-files \
|    -lcmocka -lapr-1 \
|    -I/usr/include/apache2 -I/usr/include/apr-1.0
| ./run_test
