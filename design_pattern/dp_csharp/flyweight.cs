public class Font:Object{ //(12 bytes+8 bytes)*n
	string fontName;// 4bytes
	int size; //4 bytes
	Color color; // 4 bytes

	// rewrite Font.Equals
}

public class Character{ //(2+4+20+2 +8) bytes = 36 bytes
	char c; // 2 bytes = 16 bits
//	Font f; //20 bytes

	private static Hashtable fontTable;//be a static factroy?
	public void SetFont(string name, int size, Color colr){
		Font f = new Font(name, size,color);
	}

	Font CFont{
		get{return f;}
	        set{
	       		if(fontTable.Keys.Exist(f)){
				this.f = fontTable.Keys[f];
			} else{
				fontTable.Key.Add(value);
				this.f = value;
			}
		}	       
	}
}

class System{
	public static void Main(){
		// 36bytes*100000 = 3600,000 bytes=3.6M
		ArrayList list = new ArrayList(100000);
		Font f1 = new Font("songti", 5, Color.Red);
		Font f2 = new Font("songti", 5, Color.Red);

		Charactor c = //new Charactor();
		c.chr = 'a';
		c.CFont = f1;

		Charactor c2 = //new Charactor();
		c.chr = 'a';
		c.CFont = f2;

		
	}
}
