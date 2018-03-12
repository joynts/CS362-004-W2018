// Final Project CS 362
import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {
    
    
    public UrlValidatorTest(String testName) {
        super(testName);
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
