*case_2.sp comment
R1 1 2 10
C1 2 3 1p
L1 4 6 1K
V1 2 5 DC 1
I1 2 3 DC 2
.DC V1 0 10 1
.PRINT DC V(1) I(1,2)
.PLOT DC V(1) I(1,2)
.END
