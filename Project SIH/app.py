from flask import Flask, render_template, request

app = Flask(__name__)

# Dummy dataset for chatbot (you can replace this with your dataset)
dataset = {
    "what is your name?": "My name is ChatBot.",
    "how are you?": "I'm just a computer program, so I don't have feelings.",
    "default_response": "I'm not sure how to answer that."
}

def chatbot_response(user_input):
    return dataset.get(user_input.lower(), dataset["default_response"])

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/ask", methods=["POST"])
def ask():
    user_input = request.form.get("user_input")
    response = chatbot_response(user_input)
    return render_template("index.html", user_input=user_input, response=response)

if __name__ == "__main__":
    app.run(debug=True)
