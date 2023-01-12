#ifndef DOLPROXY_SRC_LIB_DLP_LIB_H
#define DOLPROXY_SRC_LIB_DLP_LIB_H

#define dlp_offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/*
 * dv_container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member.
 * @type:   the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 */
#define dlp_container_of(ptr, type, member) ({          \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

#define DLP_ARRAY_SIZE(array)   (sizeof(array)/sizeof(array[0]))

#endif
