// Final Project CS 362

import junit.framework.TestCase;
import java.util.Random;

public class UrlValidatorTest extends TestCase {
    
    
    public UrlValidatorTest(String testName) {
        super(testName);
    }
    
    public void testIsValid()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        Random rand = new Random();
        boolean URLboolean = false;
        
        
        for(int i=0;i<100000;i++)
        {
        	StringBuilder testBuffer = new StringBuilder();
            int schemaIndex = rand.nextInt(testSchemas.length);
            int hostIndex = rand.nextInt(testHosts.length);
            int portIndex = rand.nextInt(testPorts.length);
            int pathIndex = rand.nextInt(testPaths.length);
            int queryIndex = rand.nextInt(testQueries.length);
            int fragmentIndex = rand.nextInt(testFragments.length);
            testBuffer.append(testSchemas[schemaIndex].item);
            testBuffer.append(testHosts[hostIndex].item);
            testBuffer.append(testPorts[portIndex].item);
            testBuffer.append(testPaths[pathIndex].item);
            testBuffer.append(testQueries[queryIndex].item);
            testBuffer.append(testFragments[fragmentIndex].item);
            
            String URLstring = testBuffer.toString();
        
            
            if (testSchemas[schemaIndex].valid && testHosts[hostIndex].valid
            		&& testPorts[portIndex].valid && testPaths[pathIndex].valid
            		&& testQueries[queryIndex].valid && testFragments[fragmentIndex].valid){
                   URLboolean = true;
              }
            else{
                URLboolean = false;
            }
            
            System.out.println(String.format("Test #: %s",i ));
            System.out.println(String.format("Generated url: %s. is valid: %s. And test is valid: %s.", URLstring, URLboolean,urlVal.isValid(URLstring)));
            assertEquals(URLboolean, urlVal.isValid(URLstring));
        }
        
    }
    
    ResultPair[] testSchemas = {
    new ResultPair("http://", true),
    new ResultPair("https://", true),
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
    new ResultPair("www.amazon.com", true),
    new ResultPair("www.google.com", true),
    new ResultPair("127.0.0.1", true),
    new ResultPair("amazon.com", true),
    new ResultPair("flip.engr.oregonstate.edu", true),
    new ResultPair("www.cnn.com", true),
    new ResultPair("foo.gov", true),
    new ResultPair("foo.biz", true),
    new ResultPair("foo.arpa", true),
    new ResultPair("foo.edu", true),
    new ResultPair("foo.mil", true),
    new ResultPair("foo.ai", true),
    new ResultPair("foo.bd", true),
    new ResultPair("foo.bd", true),
    new ResultPair("user@foo.gov", true),
    new ResultPair("user:pass@foo.gov", true),
    new ResultPair("", false),
    new ResultPair("amazon", false),
    new ResultPair("amazon.", false),
    new ResultPair(".amazon", false),
    new ResultPair("www.amazon", false),
    new ResultPair("amazon com", false),
    new ResultPair("www.amazon_is_great.com", false),
    new ResultPair("www.amazon-is-great!.com", false),
    new ResultPair("www.amazon%20is%20great.com", false),
    new ResultPair("127..0.1", false),
    new ResultPair("127.1", false),
    new ResultPair(".127.0.0.1", false),
    new ResultPair("256.0.0.1", false),
    new ResultPair("127", false)
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
