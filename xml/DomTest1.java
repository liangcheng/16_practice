package xml.dom;
import java.io.File;
import javax.xml.parsers.*;

import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Element;

public class DomTest1 {

	public static void main(String [] args) throws Exception
	{
		//step1: obtain DOM parser factory(create object)
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
		
		//System.out.println("class name: "+dbf.getClass());// JAXP(java API for XML Parsing)
		
		//step2: obtain DOM parser
		DocumentBuilder db = dbf.newDocumentBuilder();
		
		//step3: parse a xml file, obtain document object(root node)
		Document document = db.parse(new File("candidate.xml")); // entrance
		
		NodeList list = document.getElementsByTagName("person");
		
		//System.out.println(list.getLength());
		for(int i=0; i<list.getLength(); ++i)
		{
			Element elem = (Element)list.item(i);
			//String content = elem.getElementsByTagName("name").item(0).getNodeValue();
			String content = elem.getElementsByTagName("name").item(0).getFirstChild().getNodeValue();
			System.out.println("name:" + content);
			
			content = elem.getElementsByTagName("address").item(0).getFirstChild().getNodeValue();
			System.out.println("address:"+content);
			
			content = elem.getElementsByTagName("tel").item(0).getFirstChild().getNodeValue();
			System.out.println("tel:"+content);
			
			content = elem.getElementsByTagName("fax").item(0).getFirstChild().getNodeValue();
			System.out.println("fax:"+content);
			
			content = elem.getElementsByTagName("email").item(0).getFirstChild().getNodeValue();
			System.out.println("email:"+content);
			
			System.out.println("----------------------------");
		}
		
	}
}
