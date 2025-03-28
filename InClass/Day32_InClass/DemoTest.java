interface IData{
	void select();
	void insert();
	void delete();
	void update();
	default void grant(){
		System.out.println("Grant of Idata called");
	}
}
class FileData implements IData{
	public void select(){
		System.out.println("File data select");
	}
	public void insert(){
		System.out.println("File data insert");
	}
	public void delete(){
		System.out.println("File data delete");
	}
	public void update(){
		System.out.println("File data update");
	}
	public void grant(){
		System.out.println("Grant in Filedata called");
	}
}
class SQLData implements IData{
	public void select(){
		System.out.println("SQL data select");
	}
	public void insert(){
		System.out.println("SQL data insert");
	}
	public void delete(){
		System.out.println("SQL data delete");
	}
	public void update(){
		System.out.println("SQL data update");
	}
}
class DemoTest {
	public static void main(String[] args){
		IData id = new FileData();
		id.select();
		id.insert();
		id.delete();
		id.update();
		id.grant();
		id = new SQLData();
		id.select();
		id.insert();
		id.delete();
		id.update();
		id.grant();
	}
}