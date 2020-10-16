#include "r_giskard_core.h"
#include "reflex_template.h"

void ur_template(void) {
    r_giskard_in(ur_template_id);
    /* code */
}

void cr_template(void) {
    r_giskard_in(cr_template_id);
    r_giskard_exec_ur();
}