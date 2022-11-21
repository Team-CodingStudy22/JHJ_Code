   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>practice30</title>
</head>
<body>
<div align="center">
<form method=post action="Practice30.jsp">
	과목타입:
	<select name="lectureType"> 
	<option value="0" selected>전공필수</option>
	<option value="1">전공선택</option>
	<option value="2">교양</option>
	<option value="3">자유선택</option>
	</select> 
	
	과목명:
	<select name="lectureTitle"> 
	<option value="0" selected>웹프로그래밍</option>
	<option value="1">운영체제</option>
	<option value="2">소프트웨어프로그래밍</option>
	<option value="3">데이터베이스개론</option>
	<option value="4">자료구조</option>
	<option value="5">네트워크</option>
	<option value="6">창의와감성</option>
	<option value="7">사회봉사</option>
	</select> 
	
	요일:
	<select name="day"> 
	<option value="0" selected>월</option>
	<option value="1">화</option>
	<option value="2">수</option>
	<option value="3">목</option>
	<option value="4">금</option>
	</select> 
	
	시간:
	<select name="time"> 
	<option value="1" selected>1</option>
	<option value="2">2</option>
	<option value="3">3</option>
	<option value="4">4</option>
	<option value="5">5</option>
	<option value="6">6</option>
	<option value="7">7</option>
	</select> 
	
	연강여부:
	<select name="consecutive"> 
	<option value="1" selected>1</option>
	<option value="2">2</option>
	<option value="3">3</option>
	<option value="4">4</option>
	</select> 
	<input type="submit" value="등록">
</form>
<hr>
<%
	String[] typeNames = {"전공필수", "전공선택", "교양", "자유선택"};
	String[] titleNames = { "웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", "자료구조", "네트워크", "창의와감성", "사회봉사" };
	String[] days = {"월", "화", "수", "목", "금"};
	
	String lectureType = request.getParameter("lectureType");
	String lectureTitle = request.getParameter("lectureTitle");
	String day = request.getParameter("day");
	String time = request.getParameter("time");
	String consecutive = request.getParameter("consecutive");
	
	ArrayList<String> timetable= (ArrayList<String>)application.getAttribute("timetable");
	if(timetable == null){
		timetable = new ArrayList<String>();	
	}
	
	if(lectureType != null && lectureTitle != null && day != null && time != null && consecutive != null){
		timetable.add(typeNames[Integer.parseInt(lectureType)] + "/" + titleNames[Integer.parseInt(lectureTitle)] + "/" + days[Integer.parseInt(day)] + "/" + time + "/" + consecutive);
		application.setAttribute("timetable", timetable);	
	}
	
	if(timetable != null) {
		for(String timetables : timetable)
			out.println(timetables + "<BR>");	
	}
%>
</div>
</body>
</html>