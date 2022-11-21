package jspbook.pr32;

import java.util.*;

public class AddrManager{
	List<AddrBean> addrlist = new ArrayList<AddrBean>();
	List<AddrBean> grouplist = new ArrayList<AddrBean>();
	
	public void add(AddrBean ab) {
		addrlist.add(ab);
		grouplist.add(ab);
	}
	
	public List<AddrBean> getAddrList() {
		return addrlist;
	}
	
	public List<AddrBean> getGroupList() {
		Collections.sort(grouplist);
		return grouplist;
	}
	
	public AddrBean getAddr(String username) {
		for(AddrBean ab : addrlist) {
			if(ab.getUsername().equals(username))
				return ab;
		}
		return null;
	}
}
