import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.TableItem;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

public class ControlGroup5
{
	Group group;
	Text text;
	Button button;
	Group buttonGroup;
	Button buttonLeft;
	Button buttonRight;
	Table table;
	String[] titles = { "Col 1", "Col 2" }; //add title to increase columns number
	TableColumn column;
	TableItem[] selectedItem;
	int movePos = 0;
	
	
	ControlGroup5(Shell parentShell) 
	{			
			group = new Group(parentShell, SWT.NONE);
			group.setLayout(new RowLayout(SWT.VERTICAL));
			
			text = new Text(group, SWT.NULL);
			text.setLayoutData(new RowData(182, 50));
			
			button = new Button(group, SWT.PUSH);
			button.setText("Click Me");
			button.setLayoutData(new RowData(190, 50));
			button.addSelectionListener(new SelectionListener()
			{
				@Override
				public void widgetSelected(SelectionEvent event) 
				{
					if (!text.getText().equals(""))
					{
						TableItem item = new TableItem(table, SWT.NULL);
						item.setText(0, text.getText());
						for (int currColumn = 1; currColumn < table.getColumnCount(); currColumn++)
						{
							item.setText(currColumn, "");
						}
					}
				}
				    	
				@Override
				public void widgetDefaultSelected(SelectionEvent event) {}
			});
		
		buttonGroup = new Group(group, SWT.NONE);
		buttonGroup.setLayout(new FillLayout(SWT.HORIZONTAL));
		
		buttonLeft = new Button(buttonGroup, SWT.PUSH);
		buttonLeft.setText("<<");
		buttonLeft.addSelectionListener(new SelectionListener() 
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
				moveColumn("left");
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		
		buttonRight = new Button(buttonGroup, SWT.PUSH);
		buttonRight.setText(">>");
		buttonRight.addSelectionListener(new SelectionListener() 
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
				moveColumn("right");
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		
		table = new Table(group, SWT.BORDER | SWT.FULL_SELECTION);
		table.setLayoutData(new RowData(170, 175));
		
		for (int currTitle = 0; currTitle < titles.length; currTitle++)
		{
			column = new TableColumn(table, SWT.LEFT);
			column.setWidth(93);
		    column.setText(titles[currTitle]);
		}
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		
		table.addListener(SWT.Selection, new Listener() 
		{
		      public void handleEvent(Event event) 
		      {
		    	  selectedItem = table.getSelection();
		    	  for (int currCell = 0; currCell < titles.length; currCell++)
		    	  {
		    		  if (!selectedItem[0].getText(currCell).equals(""))
		    		  {
		    			  movePos = currCell;
		    		  }
		    	  }
		      }
		    });
	}
	
	private void moveColumn(String direction)
	{
		if(selectedItem != null)
		{
			int prevPos = movePos;
			if (direction.equals("left"))
			{
				movePos--;
				if (movePos < 0)
				{
					movePos = prevPos = 0;
				}
			}
			else if (direction.equals("right"))
			{
				movePos++;
				if (movePos == table.getColumnCount())
				{
					movePos = prevPos = table.getColumnCount() - 1;
				}
			}
	
			String temp = selectedItem[0].getText(prevPos);
			selectedItem[0].setText(prevPos, "");
			selectedItem[0].setText(movePos, temp);
		}
	}
}
