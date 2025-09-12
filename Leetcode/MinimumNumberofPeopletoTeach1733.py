class Solution:
    def minimumTeachings(self, totalLanguages, userLanguages, friendships):
        users_to_teach = set()
        for user1, user2 in friendships:
            user1 -= 1
            user2 -= 1
            can_communicate = False

            for lang1 in userLanguages[user1]:
                if lang1 in userLanguages[user2]:
                    can_communicate = True
                    break

            if not can_communicate:
                users_to_teach.add(user1)
                users_to_teach.add(user2)
        min_users_to_teach = len(userLanguages) + 1

        for language in range(1, totalLanguages + 1):
            count = 0
            for user in users_to_teach:
                if language not in userLanguages[user]:
                    count += 1
            min_users_to_teach = min(min_users_to_teach, count)

        return min_users_to_teach
