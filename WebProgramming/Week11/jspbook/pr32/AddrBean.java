package jspbook.pr32;

public class AddrBean implements Comparable<AddrBean>{
	private String username;
	private String tel;
	private String email;
	private String gender;
	private int group;
	
	public int getGroup() {
		return group;
	}
	public void setGroup(int group) {
		this.group = group;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getTel() {
		return tel;
	}
	public void setTel(String tel) {
		this.tel = tel;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	
	@Override 
	public int compareTo(AddrBean addrbean) {
		if(addrbean.group < group)
			return 1;
		else if(addrbean.group > group)
			return -1;
		return 0;
	}
}
