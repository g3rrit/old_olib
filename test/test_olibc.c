#include "show.h"

#include "olibc.h"

describe(oblic) {

	it("creating pointer, sharing and dropping") {
		void _drop(void *t) { 
		}

		void *p = ptr(10, &_drop);
		share(p); share(p); share(p);
		drop(p); drop(p) drop(p);
	}

}

snow_main();

