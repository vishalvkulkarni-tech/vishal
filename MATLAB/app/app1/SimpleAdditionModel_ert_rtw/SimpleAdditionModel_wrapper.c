#include "mex.h"
#include "SimpleAdditionModel.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Initialize model */
    SimpleAdditionModel_initialize();

    /* Step model */
    SimpleAdditionModel_step();

    /* Terminate model */
    }
