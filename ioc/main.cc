#include <iostream>
#include <list>
#include <string>
#include <vector>

class Movie {
 public:
  std::string getDirector() const { return director_; }
 private:
  std::string director_;
};

namespace version1 {

// The real point of this article is this finder object
// or particularly how we connect the lister objecet with
// a particular finder object
//
// The reason why this is interesting is that I want
// my wonderful moviesDirectedBy method to be completely
// independent of how all the movies are being stored.

class MovieFinder {
 public:
  std::list<Movie> findAll() const { return movie_list_; }
 private:
  std::list<Movie> movie_list_;
};

class MovieLister {
 public:
  std::vector<Movie> moviesDirectedBy(const std::string& director) {
    auto all_movies = finder_.findAll();
    std::vector<Movie> ret;
    for (const auto& a_movie: all_movies) {
      if (a_movie.getDirector() == director) {
        ret.push_back(a_movie);
      }
    }
    return ret;
  }
 private:
  MovieFinder finder_;
};

};  // namespace version1

namespace version2 {

// We described this situtation as a Plugin. The implementation class for
// the finder isn't linked into the program at compile time, since I don't
// know what my friends are going to use.
// Instead we want my lister to work with any implementation, and for that
// implementation to be plugged in at some later point, out of my hands.
// The problem is how can I make that link so that my lister class is
// ignorant of the implementation class, but can still talk to an instance
// to do its work.
//
// So the core problem is how do we assemble these plugins into an allication?
// This is one of the main problems that this new breed of lightweight containers face,
// and universally they all do it using Inversion of Control.

// interface for movie finder
class MovieFinder {
 public:
  virtual ~MovieFinder() = default;

  virtual std::list<Movie> findAll() const = 0;
};

class ActionMovieFinder : public MovieFinder {
 public:
  std::list<Movie> findAll() const override { return movie_list_; }
 private:
  std::list<Movie> movie_list_;
};

// We would prefer it if it were on dependent on the interface.
class MovieLister {
 public:
  std::vector<Movie> moviesDirectedBy(const std::string& director) {
    finder_ = new ActionMovieFinder();
    auto all_movies = finder_->findAll();
    std::vector<Movie> ret;
    for (const auto& a_movie: all_movies) {
      if (a_movie.getDirector() == director) {
        ret.push_back(a_movie);
      }
    }
    delete finder_;
    return ret;
  }
 private:
  MovieFinder* finder_;
};

}  // namespace version2


int main(void) {
  std::cout << (1 << 5) << std::endl;
  return 0;
}
