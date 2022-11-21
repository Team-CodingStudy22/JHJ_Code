package jspbook.pr35;

import java.util.*;

public class LectureManager {
	ArrayList<String> lectureList = new ArrayList<String>();
	
	public List<String> getLectureList(){
		return lectureList;
	}
	
	public void add(String lbean) {
		lectureList.add(lbean);
	}
}
