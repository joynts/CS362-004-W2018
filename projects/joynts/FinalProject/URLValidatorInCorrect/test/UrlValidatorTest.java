// Final Project CS 362
import junit.framework.TestCase;
import java.util.Random;

public class UrlValidatorTest extends TestCase {
	
	int NUM_TESTS = 1000;
	
	String[] validSchemes = new String[] {"http", "ftp", "https"};
	String[] validAuthorities = new String[] {"www.amazon.com", "amazon.au", "255.255.255.255"};
	String[] validPorts = new String[] {":80", ":655", ":0", ""};
	String[] validPaths = new String[] {"/test", "/787841", "/test/", "", "/test/file"};
	
	String[] invalidSchemes = new String[] {"3ht://", "http:/", "http/", "://", "", "h3t://"};
	String[] invalidAuthorities = new String[] {"amazon.ckaso", "", "aaa", "1.2.3.4.5"};
	String[] invalidPorts = new String[] {":alkj", "80aewt", ":-5"};
	String[] invalidPaths = new String[] {"//test", "/test//file", "/.../"};
	
	String[] queries = new String[] {"", "?action=view"};
	
	String[][] validPartitions = new String[][] {validSchemes, validAuthorities, validPorts, validPaths, queries};
	String[][] invalidPartitions = new String[][] {invalidSchemes, invalidAuthorities, invalidPorts, invalidPaths, queries};
    
    public UrlValidatorTest(String testName) {
        super(testName);
    }
	
	public void testManualTest01()
   {
	   // standard options
	   UrlValidator urlVal = new UrlValidator();
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.google.com/index.html"));
	   assertTrue(urlVal.isValid("http://www.google.com:80/index.html"));
	   assertTrue(urlVal.isValid("http://www.google.com:80/home/index.html"));
	   assertTrue(urlVal.isValid("https://www.google.com")); 
	   assertTrue(urlVal.isValid("ftp://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.google.com/path.html#Fragment"));
	   assertFalse(urlVal.isValid("http://www.google.com//path.html#Fragment"));
	   assertFalse(urlVal.isValid("htttp://www.google.com/path.html#Fragment"));
	   assertFalse(urlVal.isValid("www.google.com"));
	   assertFalse(urlVal.isValid("http://google.com///index.html"));	 
	   assertFalse(urlVal.isValid("ht://www.google.com/path.html#Fragment"));
	   assertFalse(urlVal.isValid(null));
   }
   
   public void testManualTest02()
   {
	   // Fragment testing
	   UrlValidator urlVal = new UrlValidator(UrlValidator.NO_FRAGMENTS);
	   assertTrue(urlVal.isValid("http://www.google.com/path.html"));
	   assertFalse(urlVal.isValid("http://www.google.com/path.html#Fragment"));
   }
   
   public void testYourPartitions()
   {
	 // Testing all valid URL partitions
	   UrlValidator urlVal = new UrlValidator();
	   Random rand = new Random();
	   String partition;
	   
	   for (int i = 0; i < NUM_TESTS; i++) {
		   StringBuilder url = new StringBuilder();
		   for (int j = 0; j < validPartitions.length; j++) {
			   // Use a random partition and create a new url
			   partition = validPartitions[j][rand.nextInt(validPartitions[j].length)];
			   url.append(partition);
			   
			   // check individual partitions for correctness.
			   // isValidAuthority checks the combination of authority and port
			   switch (j) {
			   case 0:
				   url.append("://");  // isValidScheme will fail if "://" is included
				   assertTrue(urlVal.isValidScheme(partition));
				   break;
			   case 1:
				   partition += validPartitions[2][rand.nextInt(validPartitions[2].length)]; // Add random port to the partition
				   assertTrue(urlVal.isValidAuthority(partition));
				   break;
			   case 3:
				   assertTrue(urlVal.isValidPath(partition));
				   break;
			   case 4:
				   assertTrue(urlVal.isValidQuery(partition));
				   break;
			   }
		   }
		   assertTrue(urlVal.isValid(url.toString()));
	   }
   }
    
    public void testIsValid()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        boolean URLboolean = false;
        String[] array_str = {"testSchemas","testHosts","testPorts","testPaths","testQueries","testFragments"};
        
        for(int i=0;i<testSchemas.length;i++)
        {
        	array_str[0] = testSchemas[i].item;
        	
        	for(int j=0; j<testHosts.length;j++)
        	{
        		array_str[1] = testHosts[j].item;
        		
        		for(int k=0; k<testPorts.length;k++)
            	{
            		array_str[2] = testPorts[k].item;
            		
            		for(int l=0; l<testPaths.length;l++)
                	{
                		array_str[3] = testPaths[l].item;
                		
                		for(int m=0; m<testQueries.length;m++)
                    	{
                    		array_str[4] = testQueries[m].item;
                    		
                    		for(int n=0; n<testFragments.length;n++)
                        	{
                        		array_str[5] = testFragments[n].item;
                        		String URLstring = array_str[0] + array_str[1] + array_str[2] + array_str[3] + array_str[4]+ array_str[5];
             
            
                        		if (testSchemas[i].valid && testHosts[j].valid && testPorts[k].valid && testPaths[l].valid && testQueries[m].valid && testFragments[n].valid){
                        			URLboolean = true;
                        		}
                        		else{
                        			URLboolean = false;
                        		}
            
                        		System.out.println(String.format("Generated url: %s. is valid: %s. And test is valid: %s.", URLstring, URLboolean,urlVal.isValid(URLstring)));
                        		assertEquals(URLboolean, urlVal.isValid(URLstring));
                        	}
                    	}
                	}
            	}
        	}
        }
        
    }
    
    ResultPair[] testSchemas = {
    new ResultPair("https://", true),
    new ResultPair("http://", true),
    new ResultPair("ftp://", true),
    new ResultPair("bob://", true),
    new ResultPair("ft.p://", true),
    new ResultPair("ht-tp://", true),
    new ResultPair("ht+tp://", true),
    new ResultPair("http123://", true),
    new ResultPair("123http://", false),
    new ResultPair("+http://", false),
    new ResultPair("-http://", false),
    new ResultPair(".http://", false),
    new ResultPair("http:////", false),
    new ResultPair("http//", false),
    new ResultPair("http:/", false),
    new ResultPair("", false),
    new ResultPair("://", false)
    };
    
    ResultPair[] testHosts = {
    new ResultPair("www.apple.com", true),
    new ResultPair("www.google.com", true),
    new ResultPair("127.0.0.1", true),
    new ResultPair("google.com", true),
    new ResultPair("flip.engr.oregonstate.edu", true),
    new ResultPair("www.cnn.com", true),
    new ResultPair("foo.gov", true),
    new ResultPair("foo.biz", true),
    new ResultPair("foo.arpa", true),
    new ResultPair("foo.edu", true),
    new ResultPair("foo.mil", true),
    new ResultPair("foo.ai", true),
    new ResultPair("foo.bd", true),
    new ResultPair("foo.vi", true),
    new ResultPair("user@foo.gov", true),
    new ResultPair("user:pass@foo.gov", true),
    new ResultPair("", false),
    new ResultPair("google", false),
    new ResultPair("google.", false),
    new ResultPair(".google", false),
    new ResultPair("www.google", true),
    new ResultPair("google com", false),
    new ResultPair("www.google_great.com", false),
    new ResultPair("www.google!.com", false),
    new ResultPair("www.google%20is%20good.com", false),
    new ResultPair("10..1.1", false),
    new ResultPair("10.0", false),
    new ResultPair(".10.0.1.1", false),
    new ResultPair("10.0.1.1", true),
    new ResultPair("10", false)
    };
    
    ResultPair[] testPorts = {
    new ResultPair("", true),
    new ResultPair(":80", true),
    new ResultPair(":8080", true),
    new ResultPair(":65535", true),
    new ResultPair(":65536", false),
    new ResultPair(":24b", false),
    new ResultPair(":-80", false),
    new ResultPair(":AA", false)
    };
    
    ResultPair[] testPaths = {
    new ResultPair("", true),
    new ResultPair("/path", true),
    new ResultPair("/path/name", true),
    new ResultPair("/path2/../path1", true),
    new ResultPair("/path2/..path1", true),
    new ResultPair("/name;v=1.1", true),
    new ResultPair("/name,v=1.1", true)
    };
    
    ResultPair[] testQueries = {
    new ResultPair("", true),
    new ResultPair("?lvalue=rvalue", true),
    new ResultPair("?lvalue=rvalue&lvalue2=rvalue2", true),
    new ResultPair("?lvalue=rvalue:lvalue2=rvalue2", true),
    new ResultPair("?=rvalueonly", true)
    };
    
    ResultPair[] testFragments = {
    new ResultPair("", true),
    new ResultPair("#top", true),
    new ResultPair("#top/one/two", true),
    new ResultPair("#bottom?top", true),
    new ResultPair("#top..bottom", true),
    new ResultPair("#123", true)
    };
    
    
    
}
