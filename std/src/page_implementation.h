#ifndef _STD_PAGEIMPLEMENTATION_INCLUDED
#define _STD_PAGEIMPLEMENTATION_INCLUDED

#include <std/constant_symbols.h>
#include <std/page.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

std_PageResult _std_page_create_impl(std_Page* page);
void _std_page_destroy_impl(std_Page page);

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

