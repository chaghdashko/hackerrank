import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ACMICPCTeam {
	public static void main(String[] args) {
		new ACMICPCTeam();
	}

	public ACMICPCTeam() {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		scanner.nextLine();

		List<String> list = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			list.add(scanner.nextLine());
		}

		List<Pair> pairs = getCombinations(list);

		int max = 0;
		Map<Integer, Integer> map = new HashMap<>();

		for (Pair pair : pairs) {
			int sum = 0;

			for (int i = 0; i < m; i++) {
				if (pair.s1.charAt(i) == '1' || pair.s2.charAt(i) == '1') {
					sum++;
				}
			}

			if (map.containsKey(sum)) {
				Integer noOfTeams = map.get(sum);
				noOfTeams++;
				map.put(sum, noOfTeams);
			} else {
				map.put(sum, 1);
			}

			if (sum > max) max = sum;
		}

		System.out.println(max);
		System.out.println(map.get(max));
	}

	private List<Pair> getCombinations(List<String> list) {
		List<Pair> pairs = new ArrayList<>();

		for (int i = 0; i < list.size() - 1; i++) {
			for (int j = i + 1; j < list.size(); j++) {
				pairs.add(new Pair(list.get(i), list.get(j)));
			}
		}

		return pairs;
	}

	private class Pair {
		String	s1;
		String	s2;

		public Pair(String s1, String s2) {
			this.s1 = s1;
			this.s2 = s2;
		}
	}
}
