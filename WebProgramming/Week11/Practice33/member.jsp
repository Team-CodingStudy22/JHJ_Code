  <%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>member</title>
    <style>
        table {
            border-collapse: collapse;
            border:solid 1px #000000;
        }
        
        input.imageAlign {
            vertical-align: middle;
        }

        .td1 {
            width : "80px";
            background-color : #ebecec;
            text-align: center;
            font-weight: 600;
        }

        .td2 {
            width: "500px";
        }

        #num1 {
            text-align: center;
        }
    </style>
</head>
<body>
    <div align = "center">
       <img src = "image/eclass_title.jpg">
       <form name = "form3" method = post action=register.jsp>
       <table border = "1">
        <td class = "td1" colspan="2">회원 가입</td>
        <tr>
            <td class = "td1">아이디</td>
            <td class = "td2"><input type = "text" size = "15px" name = "id">  <input type = "image" src="image/check.gif" class="imageAlign" size = "20px"></td>
        </tr>

        <tr>
            <td class = "td1">패스워드</td>
            <td class = "td2"><input type = "password" size = "15px" name = "pw"></td>
        </tr>

        <tr>
            <td class = "td1">성별</td>
            <td class = "td2"><input type = "radio" name = "gender" value="0">남<input type = "radio" name = "gender" value="1" checked>여</td>
        </tr>

        <tr>
            <td class = "td1">국적</td>
            <td class = "td2"><input type = "text" value="대한민국" size = "22px" readonly>  <input type = "text" value="국적변경" disabled size = "5px" id = "num1"></td>
        </tr>

        <tr>
            <td class = "td1">휴대폰</td>
            <td class = "td2">
                <select name = "phone1">
                    <option value = "0" selected>010</option>
                    <option value = "1">011</option>
                    <option value = "2">017</option>
                    <option value = "3">070</option>
                </select>
                -
                <input type = "text" size = "4px" name = "phone2">
                -
                <input type ="text" size = "4px" name = "phone3">
            </td>
        </tr>

        <tr>
            <td class = "td1">이메일</td>
            <td class = "td2"><input type = "text" size = "38px" name = "email"></td>
        </tr>

        <tr>
            <td class = "td1">생일</td>
            <td class = "td2"><input type = "date" name = "birth"></td>
        </tr>

        <tr>
            <td class = "td1">관심분야</td>
            <td class = "td2">
                <input type = "checkbox" name="hobby" value = "0">뉴스
                <input type = "checkbox" name="hobby" value = "1" checked>맛집
                <input type = "checkbox" name="hobby" value = "2">책
                <input type = "checkbox" name="hobby" value = "3">영화
                <input type = "checkbox" name="hobby" value = "4">여행
            </td>
        </tr>

        <tr>
            <td class = "td1">가입인사</td>
            <td class = "td2"><textarea cols = "45px" rows ="5px" name ="memo">회원들에게 간단한 가입인사를 남겨주세요</textarea></td>
        </tr>

        <tr>
            <td class = "td1">증명사진</td>
            <td class = "td2"><input type = "file"></td>
        </tr>
        <tr>
            <td class = "td1" colspan="2">
                <input type = "submit" value = "가입하기">
                <input type = "reset" value = "다시작성">
            </td>
        </tr>
    </table>
</form>
    </div>
</body>
</html></html>