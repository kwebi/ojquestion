import java.util.*;

public class Lc140 {
    private Map<String, List<String>> cache = new HashMap<String, List<String>>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        if (cache.containsKey(s)) return cache.get(s);
        List<String> result = new ArrayList<String>();
        if (s.length() == 0) {
            result.add("");
            return result;
        }

        for (String word : wordDict) {
            if (s.startsWith(word)) {
                List<String> subWords = wordBreak(s.substring(word.length()), wordDict);
                for (String subWord : subWords) {
                    result.add(word + (subWord.isEmpty() ? "" : " ") + subWord);
                }
            }
        }
        cache.put(s, result);
        return result;
    }
    public static void main(String[] args) {
        System.out.println(new Lc140().wordBreak("catsanddog", Arrays.asList("cat", "cats", "and", "sand", "dog")));
    }
}
