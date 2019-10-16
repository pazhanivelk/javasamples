import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class StreamAPI {

    public static void main(String args[]){

        intSteamDemo();
        filterCollectAndSortDemo();
    }

    public static void filterCollectAndSortDemo (){
        List<Integer> intArray1 = Arrays.asList(3,2,6,9,3,2,12,44,8888,33,22,2);
        List<Integer> intArray2 = Arrays.asList(1009, 9282, 8993, 2888, 2737, 2, 1, 1);


        Set<Integer> intSet = intArray1.stream().collect(Collectors.toSet());
        System.out.println("Collected as Set ....."+intSet);

        List<Integer> intArraySorted = intArray1.stream().sorted().filter(integer -> integer%2 == 0).collect(Collectors.toList());
        System.out.println("Sorted Array "+intArraySorted);

        Map<String, List<Integer>> integerMap = new HashMap<>();
        integerMap.put("intArray1", intArray1);
        integerMap.put("intArray2", intArray2);


        List<Integer> flatvalues = integerMap
                .values()
                .stream()
                .flatMap(value -> value.stream())
                .sorted().collect(Collectors.toList());

        System.out.println("flatValues Sorted " + flatvalues);
    }

    public static void intSteamDemo(){

        OptionalInt i = IntStream.rangeClosed(0,10).reduce((left, right) -> {
            System.out.println(left + " : "+ right);
            return left+right;
        });

        OptionalInt k = IntStream.rangeClosed(0,10).reduce((left, right) ->
                left+right
        );
        System.out.println(i);
        int sum = 0;
        for (int j=0; j<=10; j++){
            sum = sum +j;

        }
        System.out.println(sum);
    }

}
