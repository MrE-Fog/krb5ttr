/*
 * $Source$
 * $Author$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 *
 * For copying and distribution information, please see the file
 * <krb5/copyright.h>.
 *
 * krb5_free_address()
 */

#if !defined(lint) && !defined(SABER)
static char rcsid_f_address_c [] =
"$Id$";
#endif	/* !lint & !SABER */

#include <krb5/copyright.h>
#include <krb5/krb5.h>
#include <krb5/ext-proto.h>

void
krb5_free_address(val)
krb5_address **val;
{
    register krb5_address **temp;

    for (temp = val; *temp; temp++) {
	if ((*temp)->contents)
	    xfree((*temp)->contents);
	xfree(*temp);
    }
    xfree(val);
    return;
}
