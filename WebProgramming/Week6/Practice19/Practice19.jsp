   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import ="java.util.Calendar" %>
    
<%!
	public String parseDay(int cnt, String day)
	{
		if(cnt % 7 == 0)
			return "<font color = 'red'>" + day + "</font>";
		else if (cnt % 7 == 6)
			return "<font color = 'blue'>" + day + "</font>";
		else return day;
			
	}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Calendar</title>
<style>
	h3 {
		text-align : right;
	}
	
	table {
		
		border : solid 1px #000000;
		text-align : center;
		font-size : 18px;
		border-collapse : collapse;
	}
	
	td {
		width : 70px;
	}
	
</style>
</head>
<body>
<div align = "center">
<%
	Calendar Today_cal = Calendar.getInstance();
	Calendar cal = Calendar.getInstance();
	cal.set(2022, Calendar.OCTOBER, 1);
	
	int today_year = Today_cal.get(Calendar.YEAR);
	int today_month = Today_cal.get(Calendar.MONTH);
	int today_date = Today_cal.get(Calendar.DATE);
	
	int year = cal.get(Calendar.YEAR);
	int month = cal.get(Calendar.MONTH);
	int date = cal.get(Calendar.DATE);
	
	int day = cal.get(Calendar.DAY_OF_WEEK);
	String[] days = {"일", "월", "화", "수", "목", "금", "토"};
	
	int startDay = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	
	int i; 
	int j = startDay;

	out.println("<h3>" + today_year + "-" + (today_month + 1) + "-" + today_date + "&nbsp;&nbsp;</h3>");
	
	out.println("<table border = '1' width = '800' height = '300'>");
	
	out.println("<tr>");
	for(i = 0; i < 7; i++)
		out.println("<td>" + parseDay(i, days[i]) +"</td>");		
	out.println("</tr>");
	
	out.println("<tr>");
	for(i = 0; i < startDay - 1; i++) {
		out.println("<td>&nbsp;</td>");
	}
	
	for(i = 1; i <= end; i++) {
		out.print("<td>" + parseDay(j - 1, Integer.toString(i)) + "</td>");
		if(j % 7 == 0) {
			out.println("</tr>");
			out.println("<tr>");
		}
		j++;
	}
	
	while(j % 7 != 0) {
		out.println("<td>&nbsp;</td>");
		j++;
	}
	out.println("</tr>");
	
	out.println("</table>");
%>	
</div>	
</body>
</html>