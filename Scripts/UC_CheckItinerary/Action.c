Action()
{
	lr_start_transaction("UC2_CheckItinerary");

/*Correlation comment - Do not change!  Original value='136368.564277035HAVttfipAcftcAizpHtiVf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
		lr_start_transaction("loginPage");
		
		
web_reg_find("Text=Web Tours",
		LAST);
		
		
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(13);
	
	lr_end_transaction("loginPage",LR_AUTO);

	login();

	

	lr_think_time(16);

	

	lr_start_transaction("checkItinerary");
	
	web_reg_find("Text={firstname} {lastname}",LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("checkItinerary",LR_AUTO);

	lr_think_time(23);

	logout();

	lr_end_transaction("UC2_CheckItinerary", LR_AUTO);

	return 0;
}