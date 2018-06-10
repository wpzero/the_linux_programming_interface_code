# Makefile.inc - common definitions used by all makefiles

TLPI_DIR = ..
TLPI_LIB = ${TLPI_DIR}/libtlpi.a
TLPI_INCL_DIR = ${TLPI_DIR}/lib

# 这个是realtime library
LINUX_LIBRT = -lrt
# libdl dladdr dlclose dlopen dlsym dlerror
# 动态链接相关
LINUX_LIBDL = -ldl
# acess control list
LINUX_LIBACL = -lacl
# 加密相关的lib md5/sha-256/sha-512
LINUX_LIBCRYPT = -lcrypt
# 权限相关的
LINUX_LIBCAP = -lcap

# "-Wextra" is a more descriptive synonym for "-W", but only
# available in more recent gcc versions

# Defining _DEFAULT_SOURCE is a workaround to avoid the warnings that
# would otherwise be produced when compiling code that defines _BSD_SOURCE
# or _SVID_SOURCE against glibc headers in version 2.20 and later.
# (The alternative would be to replace each instance of "#define _SVID_SOURCE"
# or "#define _BSD_SOURCE" in the example programs with
# "#define _DEFAULT_SOURCE".)

IMPL_CFLAGS = -std=c99 -D_XOPEN_SOURCE=600 \
                -D_DEFAULT_SOURCE \
                -g -I${TLPI_INCL_DIR} \
                -pedantic \
                -Wall \
                -W \
                -Wmissing-prototypes \
                -Wno-sign-compare \
                -Wno-unused-parameter

CFLAGS = ${IMPL_CFLAGS}

IMPL_THREAD_FLAGS = -pthread

IMPL_LDLIBS = ${TLPI_LIB} -lm

LDLIBS = ${IMPL_LDLIBS}

RM = rm -f
