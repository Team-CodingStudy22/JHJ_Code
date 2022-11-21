   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%!
	int[][]lectureType ={
		{0, 1, 1, 0, 1}, 
		{1, 0, 0, 0, 2}, 
		{0, 0, 2, 0, 4}, 
		{2, 3, 0, 3, 0},
		{0 ,0, 0, 2, 0}, 
		{0, 0, 0, 0, 0} 
	};
	
	int[][] consecutive = {
		{1, 2, 1, 1, 1}, 
		{2, 0, 1, 1, 1}, 
		{0, 1, 1, 1, 4}, 
		{2, 1, 1, 1, 0}, 
		{0, 1, 1, 2, 0}, 
		{1, 1, 1, 0, 0}
	};
	
	int[][] lectureTitle = {
		{-1, 4, 5, -1, 5}, 
		{3, -1, -1, -1, 1}, 
		{-1, -1, 1, -1, 7}, 
		{0, 6, -1, 6, -1}, 
		{-1, -1, -1, 2, -1}, 
		{-1, -1, -1, -1, -1}
	};
	
	String[] titleNames = {
	"웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", "자료구조", "네트워크", "창의와감성", "사회봉사"
	}; 
%>
<html>
<head>
<meta charset="UTF-8">
<title>Practice31</title>
  <style>
        table{
            border-collapse: collapse;
            text-align: center;
            width: 480px;
            height: 48px;
            font-size: 13px;
            font-family: "굴림", Gulim, Arial, sans-serif;
        }

        td {
            width: 480px;
            height: 48px;
       
        }
        
        h2 {
            text-align: center;
            font-family: "굴림", Gulim, Arial, sans-serif;
        }

        .day {
            font-size: 20px;
            font-weight: bold;
        }
        .class0 {
        }
        .class1 {
            background-color: #FFE08C;
        }
        
        .class2 {
            background-color: #B3CCFF;  
        }
        
        .class3 {
            background-color: #BEBDBD;
        }
    </style>
</head>
<body>
	  <div align = "center">
       <h2>강의 시간표</h2>
        <table border = "1">
            <tr>
                <td class = "day">2학년</td>
                <td class = "day">월</td>
                <td class = "day">화</td>
                <td class = "day">수</td>
                <td class = "day">목</td>
                <td class = "day">금</td>
            </tr>  
<%
	int i, j;
	int type;
	String title;
	int title_num;
	int consecutive_num;
	for(i = 0; i < 6 ; i++) {
		out.println("<tr>");
		out.println("<td>" + (i + 1) + "</td>");
		for(j = 0; j < 5; j++) {
			type = lectureType[i][j];
			title_num = lectureTitle[i][j];
			consecutive_num = consecutive[i][j];
			
			if(consecutive_num == 0)
				continue;
			else if(type == 0 && title_num == -1) {
				out.println("<td> </td>");
			}
			else {
				title = titleNames[lectureTitle[i][j]];
				out.println("<td rowspan='" + consecutive_num + "' class='class" + type + "'>" + title);
				out.println("</td>");
			}
		}
		out.println("</tr>");
	}
%> 
        </table>
    </div>
</body>
</html>