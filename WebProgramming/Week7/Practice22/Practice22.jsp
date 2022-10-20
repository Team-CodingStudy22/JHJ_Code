<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import = "java.util.Enumeration" %>
     <% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	String[] mChoices = {"hobby"};
	int flag = 0;
	Enumeration<String> names = request.getParameterNames();

	while(names.hasMoreElements()) {
		flag = 0;
		String s = names.nextElement();
		
		for(int i = 0; i < mChoices.length; i++){
			if(s.equals(mChoices[i])) {
				flag = 1;
				break;
			}
		}		
		
		if(flag == 1) {
			out.print(s + " : ");
			String multies[] = request.getParameterValues(s);
			for(String h : multies) {
				out.print(h + "/");
			} 
			out.println("<br>");
		}
		else
			out.println(s + " : " + request.getParameter(s) + "<br>");
	}
%>

<hr>
<h1>Processing Parameters</h1>
<%
	String[] hobbyNames = {"뉴스", "맛집", "책", "영화", "여행"};
	String[] telCompany = {"010", "011", "017", "070"};
	String[] gNames = {"남", "여"};
	int h;
	
	Enumeration<String> names2 = request.getParameterNames();
	while(names2.hasMoreElements()) {
		String s = names2.nextElement();
		out.print(s + " : ");
		if(s.equals("hobby")){
			String multies[] = request.getParameterValues(s);
			for(int i = 0; i < multies.length; i++) {
				h = Integer.parseInt(multies[i]);
				out.print(hobbyNames[h] + "/");
			}
		}
		else if(s.equals("phone1")) {
			h = Integer.parseInt(request.getParameter(s));
			out.print(telCompany[h]);
		}
		else if(s.equals("gender")) {
			h = Integer.parseInt(request.getParameter(s));
			out.print(gNames[h]);
		}
		else
			out.println(request.getParameter(s));
		out.println("<br>");
	}
%>
</body>
</html>