   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="jspbook.pr35.*"%>
<!DOCTYPE html>
<jsp:useBean id="lecture" class="jspbook.pr35.LectureBean" />
<jsp:setProperty name="lecture" property="*" />
<jsp:useBean id="lm" class="jspbook.pr35.LectureManager" scope="application" />
<html>
<head>
<meta charset="UTF-8">
<title>practice35</title>
</head>
<body>
<div align="center">
<form method=post action="Practice35.jsp">
	과목타입:
	<select name="type"> 
	<option value="0" selected>전공필수</option>
	<option value="1">전공선택</option>
	<option value="2">교양</option>
	<option value="3">자유선택</option>
	</select> 
	
	과목명:
	<select name="title"> 
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
	if(lecture.getType() != -1 && lecture.getTitle() != -1 && lecture.getDay() != -1 && lecture.getTime() != -1 && lecture.getConsecutive() != -1)
	{
		lm.add(lecture.toString()); 
		for(String lb : lm.getLectureList()) { 
			out.println(lb + "<br>");
		}	
	}
%>
</div>
</body>
</html>