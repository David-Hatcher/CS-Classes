package stubs;
import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class LetterMapper extends Mapper<LongWritable, Text, Text, IntWritable> {

  @Override
  public void map(LongWritable key, Text value, Context context)
      throws IOException, InterruptedException {
	  
	  String line = value.toString();
	  
	  for(String word : line.split("\\W+")){
		  if(word.length() > 0){
			  /*
			   * Grabbing first letter and length of word
			   */
			  String firstLetter = word.substring(0,1);
			  int length = word.length();
			  
			  /*
			   * Writing values to key pair list
			   */
			  context.write(new Text(firstLetter), new IntWritable(length));
		  }
	  }
	  
    /*
     * TODO implement
     */

  }
}
