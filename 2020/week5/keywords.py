words = int(input())

word_list = set()

for _ in range(words):
    word = input()
    word_list.add(word.lower().replace("-", " ", len(word)))

print(len(word_list))
