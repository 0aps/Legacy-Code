#include <radc++.h>

Form 	    form1("Progress Bars - RAD C++ Example");

ProgressBar pgb1(-1,100,50,200, 20,form1,RCP_HORIZONTAL); //horizontal
ProgressBar pgb2(-1,100,80, 20,100,form1,RCP_VERTICAL);   //vertical

Label       lbl("Enter percentage",AUTO_ID,180,100,120,20,form1);
NumberBox   txt("50",AUTO_ID,180,120,120,25,form1);
Button      btn("Set Percentage %",AUTO_ID,180,155,120,25,form1);

FormProcedure proc(FormProcArgs) {
	ON_CLOSE() Application.close();
    
	ON_COMMAND_BY(btn) { //set percentage as per value of txt.text
		pgb1.percent=val(txt.text);
		pgb2.percent=val(txt.text);
	}

	return 0;
}

rad_main()

	form1.procedure = proc;
	
	//set numberbox digits limit
	txt.setLimit(3); //3 digits
	
rad_end()
