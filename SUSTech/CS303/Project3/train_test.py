import json
from sklearn import svm
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics import accuracy_score
import sklearn
import argparse


def train(args):
    with open(args.train_data_file, 'r') as f:
        data = json.loads(f.read())

        X = [item['data'] for item in data]
        y = [item['label'] for item in data]
        train_x, test_x, train_y, test_y = sklearn.model_selection.train_test_split(
            X, y, test_size=0.01)
        trans = TfidfVectorizer()
        trans.fit(train_x)

        model = svm.LinearSVC()
        print('fitting...')
        model.fit(X=trans.transform(train_x), y=train_y)

        print('predicting...')
        ans = model.predict(trans.transform(test_x))
        sol = accuracy_score(test_y, ans)
        print('model finished with an accuracy of: ' + format(sol))

        return model, trans


def test(args, model, trans):
    print('testing...')
    with open('./output.txt', 'w') as output:
        with open(args.test_data_file, 'r') as f:
            f = json.loads(f.read())
            for item in f:
                x = trans.transform([item])
                ans = model.predict(x)
                output.write(str(ans[0]))
                output.write('\n')
    print('success')


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-t', '--train_data_file',
                        type=str, default='train.json')
    parser.add_argument('-i', '--test_data_file', type=str,
                        default='testdataexample')
    args = parser.parse_args()

    # training process
    model, trans = train(args)

    # testing process
    test(args, model, trans)
