package leetCode49;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
 
public class Solution
{
    public static List<List<String>> groupAnagrams(String[] strs)
    {
        List<List<String>> result = new ArrayList<List<String>>();
        HashMap<String, List<String>> map = new HashMap<>();
        
        char[] tmpC;
        String tmpS;
        List<String> tmpL = null;
        
        for (int i = 0; i < strs.length; i++) {
        	tmpC = strs[i].toCharArray();
        	Arrays.sort(tmpC);
        	tmpS = new String(tmpC);
        	tmpL = map.get(tmpS);
        	
        	if (tmpL == null) {
        		tmpL = new ArrayList<String>();
        	}
        	
        	tmpL.add(strs[i]);
        	map.put(tmpS, tmpL);
        }
        
        for (List<String> i : map.values()) {
        	result.add(i);
        }
        
        return result;
    }
    
    public static void main(String[] args) {
		String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
		List<List<String>> result = groupAnagrams(strs);
		
		System.out.println(result);
	}
}